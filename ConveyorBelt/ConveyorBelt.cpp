// Author: Suraj Verma
// mail_id: surajverma.job@gmail.com
// mob no: +91 9916375384
#include <iostream>
#include <mutex>
#include <ostream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

using namespace std;

const string partA = "A";
const string partB = "B";
const string partC = "C";
const string noPart = "-";
const string Product = "P";

bool upper_wrk_priority{true};

enum class action {
  no_action = 0,
  pick = 1, // picking item from belt
  make = 2, // making product either AB,AC as P
  put = 3   // putting the item to the belt
};

class conveyorBelt {
  int startIndex{0};

public:
  std::vector<string> items;
  int cycle{0};
  int steps{0};
  int numLots{0};
  int total_product_made = 0;
  int const num_worker_either_side = 3;
  // start index of the belt each interval the index will be shifted to 1
  int getStartIndex() const { return startIndex; }

  // for incremneting the index after all worker action this needs to be called
  void increamentIndex() { startIndex++; }

  // this is for resetting the start index to again 0 after 1 cycle of the belt
  void resetStartIndex() { startIndex = 0; }

  // this is for intializing the coveyor belt with products {A,B,C,A,-}
  void init(int lot) {
    numLots = lot;
    for (int i = 0; i < lot; i++) {
      items.push_back(partA);
      items.push_back(partB);
      items.push_back(partC);
      items.push_back(partA);
      items.push_back(noPart);
    }

    cout << "-----------------------------conveyorBelt initial "
            "items-----------------------"
         << std::endl;
    for (auto x : items) {
      cout << x << " ";
    }
    cout << std::endl;
    cout << "-----------------------------conveyorBelt initial "
            "items------------------------"
         << std::endl;
  }

  bool find_all_are_Product() {
    total_product_made = 0;
    for (int i = 0; i < items.size(); i++) {
      if (items.at(i) == Product) {
        total_product_made++;
      }
      if ((items.at(i) == partA) || (items.at(i) == partB) ||
          (items.at(i) == partC)) {
        return false;
      }
    }
    if (total_product_made == numLots * 2) {
      return true;
    } else {
      return false;
    }
  }
};

class Worker {
  string curPartA{""};
  string curPartB_C{""};
  string curProduct{""};
  int pos_;

public:
  Worker(int pos) : pos_(pos) {}

  // for getting the item from the belt
  bool pickItem(conveyorBelt &cb) {
    string part = cb.items.at(pos_ + cb.getStartIndex());
    if (curPartA.empty() && part == partA) {
      curPartA = part;
      cb.items.at(pos_ + cb.getStartIndex()) = "-";
      return true;
    } else if (curPartB_C.empty() && (part == partB || part == partC)) {
      curPartB_C = part;
      cb.items.at(pos_ + cb.getStartIndex()) = "-";
      return true;
    }
    return false;
  }

  // for putting the item to the belt
  bool putItem(conveyorBelt &cb) {
    static int product_make_attempt_cycle = 0;
    // This is putting product policy
    if (!curProduct.empty()) {
      if (cb.items.at(pos_ + cb.getStartIndex()) == noPart) {
        cb.items.at(pos_ + cb.getStartIndex()) = curProduct;
        curPartA = "";
        curPartB_C = "";
        curProduct = "";
        product_make_attempt_cycle = 0;
        return true;
      }
    }
    // This is putting back item to empty slot of could not make product or else
    // keep holding the items will make end less waiting
    else {
      product_make_attempt_cycle++;
      if ((product_make_attempt_cycle >= 10) &&
          ((curPartA.empty() && !curPartB_C.empty()) ||
           (!curPartA.empty() && curPartB_C.empty()))) {
        if (cb.items.at(pos_ + cb.getStartIndex()) == noPart) {
          if (!curPartA.empty()) {
            cb.items.at(pos_ + cb.getStartIndex()) = curPartA;
            curPartA = "";
            product_make_attempt_cycle = 0;
          } else if (!curPartB_C.empty()) {
            cb.items.at(pos_ + cb.getStartIndex()) = curPartB_C;
            curPartB_C = "";
            product_make_attempt_cycle = 0;
          }
        }
      }
    }
    return false;
  }

  // for making product P
  bool makeProduct(conveyorBelt &cb) {
    if (!curPartA.empty() && !curPartB_C.empty() && curProduct.empty()) {
      curProduct = Product;
      return true;
    }
    return false;
  }

  // worker action can be {no_action,pick,make,put} in each time ineteval
  action singleWorkerAction(conveyorBelt &cb) {
    action ret = action::no_action;
    if (pickItem(cb)) {
      ret = action::pick;
    } else if (makeProduct(cb)) {
      ret = action::make;
    } else if (putItem(cb)) {
      ret = action::put;
    }
    return ret;
  }
};

class AllWorkers {
public:
  vector<Worker> upperWorkers;
  vector<Worker> lowerWorkers;
  const int num_max_one_side_works{3};
};

// API for calling all the worker action
void AllWorkersAction(conveyorBelt belt_line, AllWorkers allworker) {
  int num_item_slots_in_belt = belt_line.items.size();
  cout << "num of items and slots:" << num_item_slots_in_belt << std::endl;

  while (1) {
    std::thread::id this_id = std::this_thread::get_id();
    cout << "thread id:" << this_id << ", step:" << belt_line.steps + 1
         << std::endl;
    action upWorkerAct = action::no_action;
    action lowWorkerAct = action::no_action;

    // any one of the upper or lower worker can do the action on slot (pick or
    // put) but one can "make" and other can do (make, pick or put) at the same
    // interval
    if (upper_wrk_priority) {
      for (int i = 0; i < allworker.num_max_one_side_works; i++) {
        upWorkerAct =
            allworker.upperWorkers.at(i).singleWorkerAction(belt_line);
        if (upWorkerAct == action::no_action || upWorkerAct == action::make) {
          lowWorkerAct =
              allworker.lowerWorkers.at(i).singleWorkerAction(belt_line);
        }
        cout << "upper wrki" << i << ":" << static_cast<int>(upWorkerAct)
             << " lower wrki" << i << ":" << static_cast<int>(lowWorkerAct)
             << std::endl;
      }
    } else {
      for (int i = 0; i < allworker.num_max_one_side_works; i++) {
        lowWorkerAct =
            allworker.lowerWorkers.at(i).singleWorkerAction(belt_line);
        if (lowWorkerAct == action::no_action || lowWorkerAct == action::make) {
          upWorkerAct =
              allworker.upperWorkers.at(i).singleWorkerAction(belt_line);
        }
        cout << "upper wrki" << i << ":" << static_cast<int>(upWorkerAct)
             << " lower wrki" << i << ":" << static_cast<int>(lowWorkerAct)
             << std::endl;
      }
    }

    // This increment, i am considering the interval in
    // each loop so the convery belt if sifted one position
    belt_line.increamentIndex();
    auto time = 1ms;
    // every interval changing the piority for upper and lower worker
    upper_wrk_priority = (upper_wrk_priority) ? false : true;

    if (belt_line.getStartIndex() >=
        num_item_slots_in_belt - belt_line.num_worker_either_side) {
      belt_line.resetStartIndex();
      // this is increamented only if all the slots are visited
      belt_line.cycle++;
    }

    // printing current status of belt
    for (auto x : belt_line.items) {
      cout << x << " ";
    }
    cout << std::endl;
    this_thread::sleep_for(time);

    // it is increamented for every one interval which is equevalent to
    // steps
    belt_line.steps++;

    // Thread exit coniditon if all the slots are filled with product then exit
    {
      if (belt_line.find_all_are_Product()) {
        cout << "going to exit thread id:" << this_id
             << " in cycle:" << belt_line.cycle
             << " in steps:" << belt_line.steps
             << " total product:" << belt_line.total_product_made << std::endl;
        exit(0);
      }
    }
  }
}

int main() {
  conveyorBelt belt_line;
  int num_of_lot = 20; // 100 itmes = total 40 Product should come out
  belt_line.init(num_of_lot);
  /******
  Asumptions:
      num_of_lot:one lot consist five slots {A,B,C,A,-}
         v   v   v                  upper workers
        ------------------------
    -> | A | B  | C | A | - | ->    conveyor belt
        ------------------------
         ^   ^    ^                 lower workers
  ***********/

  Worker wrk_u_0(0); // this is first position upper side
  Worker wrk_u_1(1); // this is second position upper side
  Worker wrk_u_2(2); // this is third position upper side

  Worker wrk_d_0(0); // this is first position lower side
  Worker wrk_d_1(1); // this is first position lower side
  Worker wrk_d_2(2); // this is first position lower side

  AllWorkers allworker;
  allworker.upperWorkers.push_back(wrk_u_0);
  allworker.upperWorkers.push_back(wrk_u_1);
  allworker.upperWorkers.push_back(wrk_u_2);

  allworker.lowerWorkers.push_back(wrk_d_0);
  allworker.lowerWorkers.push_back(wrk_d_1);
  allworker.lowerWorkers.push_back(wrk_d_2);

  // thread for the workers
  std::thread Workersthread(AllWorkersAction, belt_line, allworker);

  Workersthread.join();

  return 0;
}

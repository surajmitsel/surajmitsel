### Failure 1:
I received the requirement from the Product Manager (PM), and my team began working on it. We created backlogs, completed tasks, and even developed a proof of concept (POC). 

However, during an early commit discussion, the Vice President (VP) disagreed with the proposed changes. The concern was that these changes were too customer- and industry-centric, potentially opening up the product to competition with industries we prefer not to compete against.

Following this, I reached out to the PM again to clarify the necessity of the feature, its customer coverage, and sales targets. It became clear that the sales potential was limited. 

As a result, we decided to drop this feature and instead focus on developing features that add more value and provide broader coverage for our customers.

### Failure 2:

The performance requirements were underestimated because they depended on a third-party library—specifically, the AWS MQTT client library—which has limitations in handling the number of messages per second. The library queues messages but drops them if they exceed a certain timeout.

To address this, we started optimizing timeouts, increasing communication speed by removing redundant checks, optimizing logging, and implementing cache reading. However, when we began measuring performance, the results actually worsened, showing poorer performance.

The root cause was the inherent limitations and dependencies of the third-party library. We researched this issue on open forums and found that we lacked the expertise to enhance the library ourselves. Additionally, we did not want to take on the responsibility of maintaining our own version of the library. Therefore, we decided to drop the enhancement.

i could have gethered more input from the team to which have the dependencies and also considered that fact if we need to propose the changes to open community will that be doable or not.

### failure 3:
for SQL instaed to include the ORM but it was decided not to because to have the open source on third party we might gonna block ourself, rather we implmeneted out own but for that i had to buy in more time to develop it which was not considerd earlier to reached to PMs to push the feature in patch realease than actual release cycle due to that. 
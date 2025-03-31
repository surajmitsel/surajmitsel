# Mocking a non-static function in a class

If you can make the `DeleteStore` function virtual but need to keep `ProcessStore` non-virtual, you can still use Google Mock to mock `DeleteStore` and test `ProcessStore`. Here’s how you can do it:

###  Define the Original Class
   Make the `DeleteStore` function virtual.

   ```cpp
   class ImageManager {
   public:
       virtual ~ImageManager() = default;

       virtual smdb_error DeleteStore(const std::string& nodeName) { // This must be virtual function
           // Implementation of function2
           return smdb_error::NetworkError;
       }

       smdb_error ProcessStore(const std::string& nodeName) {
           // Implementation of function1
           // This function calls DeleteStore
           return DeleteStore(nodeName);
       }
   };
   ```

### Define the Mock Class
Create a mock class that inherits from the original class and mock the `DeleteStore` method.

```cpp
class MockImageManager : public ImageManager {
public:
    MOCK_METHOD(smdb_error, DeleteStore, (const std::string& nodeName), (override));
};
```

### Set Up the Test
```cpp
TEST(ImageManagerTest, ProcessStoreCallsDeleteStore) {
    // Create a mock object
    MockImageManager mockImageManager;

    // Set up the expectation
    EXPECT_CALL(mockImageManager, DeleteStore(testing::_))
        .WillOnce(testing::Return(smdb_error::NetworkError));

    // Call the function1 (ProcessStore)
    smdb_error result = mockImageManager.ProcessStore("someNodeName");

    // Verify the result
    EXPECT_EQ(result, smdb_error::NetworkError);
}
```

# Mocking a static function in a class
```cpp
auto mock_eg(make_mocker(CapIdentify::isCapEnable, [](const smdb_type_text& cap) { return true; }));
```

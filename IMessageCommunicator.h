#include <string>
using namespace std;
class IMessageCommunicator{
  public:
      virtual int pushMessage(const string& message)=0;
}

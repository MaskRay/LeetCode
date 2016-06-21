// Logger Rate Limiter
class Logger {
  unordered_map<string, int> last;
public:
  /** Initialize your data structure here. */
  Logger() {

  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (! last.count(message) || last[message] <= timestamp-10) {
      last[message] = timestamp;
      return true;
    }
    return false;
  }
};

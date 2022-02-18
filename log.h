int dbgLog(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
int setupDbgLog(char *file);
void closeDbgLog();

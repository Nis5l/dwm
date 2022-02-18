#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdarg.h>

static FILE *logFile = 0;

int dbgLog(const char *format, ...) {
	if(!logFile) {
		return 1;
	}

	char date[30];
	time_t now = time(0);
	struct tm *t = localtime(&now);
	strftime(date, sizeof(date) - 1, "%H:%M:%S", t);

	char str[100];
	va_list args;
	va_start(args, format);
	if (0 > vsnprintf(str, sizeof(str), format, args)) return 2;
	va_end(args);
	fprintf(logFile, "[%s] %s\n", date, str);
	fflush(logFile);
	return 0;
}

int setupDbgLog(char *file) {
	if(!(logFile = fopen(file, "a+"))) {
		return 1;
	}

	dbgLog("logger initialized");

	return 0;
}

void closeDbgLog() {
	if(logFile) fclose(logFile);
}

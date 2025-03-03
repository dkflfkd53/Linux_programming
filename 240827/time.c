void test1(void);
void test2(void);

int main() {
	test1();
	test2();
}

#include <stdio.h>
#include <time.h>

void test() {
	printf("\ntest1 \n");
	time_t t = time(NULL);
	printf("%d\n", (int)t);
	printf("%s", ctime(&t));
	
	struct tm *ptm = gmtime(&t);
	printf("%d %d %d %d %d %d\n",
		ptm->tm_year, ptm->tm_mon, ptm->tm_mday,
		ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}

#include <sys/time.h>
#include <stdio.h>
void test2() {
	printf("\ntest2 \n");
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv, &tz);
	printf("%ld %d\n", tv.tv_sec, tv.tv_usec);
}

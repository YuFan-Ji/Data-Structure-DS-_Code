#include"Queue.h"

void QueueTest01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);

	//printf("head:%d\n", QueueFront(&q));
	//printf("tail:%d\n", QueueBack(&q));
	printf("size:%d\n", QueueSize(&q));
	QueueDestroy(&q);
}

int main()
{
	QueueTest01();
	return 0;
}
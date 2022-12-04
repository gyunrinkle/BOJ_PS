#include <stdio.h>

int findMax(int queue[], int N, int front, int rear){
	int M = queue[front], index = 0;

	for (int i = front + 1; i <= rear; i++)
		if (M < queue[i]) 
			M = queue[i], index = i;
	return index;
}

int main(){
	int tc, N, M, queue[10000], maxIndex, front, rear, now;
	scanf("%d", &tc);

	while (tc--){
		scanf("%d%d", &N, &M);
		front = now = 0, rear = N - 1;

		for (int i = 0; i < N; i++)
			scanf("%d", &queue[i]);

		while (front - 1 != M){
			maxIndex = findMax(queue, N, front, rear);
			for (int i = front; i < maxIndex; i++){
				queue[++rear] = queue[front++];
				M = M == front - 1 ? rear : M;
			}
			front++;
			now++;
		}
		printf("%d\n", now);
	}
	return 0;
}
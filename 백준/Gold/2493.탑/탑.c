#pragma warning(disable:4996)
#include<stdio.h>

int n;
int height[500000];
int recipient[500000];

int getRecipient(int senderIndex) {

	int recipientIndex = -1;
	int i;
	int senderHeight;
	int bTrigger=0;

	senderHeight = height[senderIndex];

	i = senderIndex - 1;

	while (i >= 0) {

		if(height[i]>=senderHeight){

			recipientIndex = i;
			bTrigger = 1;
			break;
		}
		else {

			i = recipient[i];
		}
		
		
	}
	if(bTrigger) return recipientIndex;
	else return -1;

}

int main() {

	int i;
	int n;

	scanf("%d",&n);

	for (i = 0; i < n; i++) {

		scanf("%d",&height[i]);
		recipient[i] = getRecipient(i);
		
	}

	for (i = 0; i < n; i++) {

		printf("%d ", recipient[i] + 1);
		
	}

	
	return 0;
}
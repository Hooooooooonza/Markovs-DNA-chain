#include <stdio.h>

#define BASE_COUNT 10

int main(void) {
	int goal1 = 0;
	int goal2 = 0;
	int curr1 = 0;
	int curr2 = 0;
	char printgoal1;
	char printgoal2;
	char data[3][BASE_COUNT] = {
        	{'a', 'c', 'c', 'g', 'c', 'g', 'c', 't', 't', 'a'},
        	{'g', 'c', 't', 't', 'a', 'g', 't', 'g', 'a', 'c'},
        	{'t', 'a', 'g', 'c', 'c', 'g', 't', 't', 'a', 'c'}
    	};
	char numdat[3][BASE_COUNT] = {0};

	for(int i = 0;i<3;i++) for(int j = 0;j<BASE_COUNT;j++) {
		if(data[i][j] == 'a') numdat[i][j] = 0;
                if(data[i][j] == 't') numdat[i][j] = 1;
                if(data[i][j] == 'c') numdat[i][j] = 2;
                if(data[i][j] == 'g') numdat[i][j] = 3;
	}

	int result[3][16] = {0};

	for(int i = 0;i<3;i++) {
		printf("index %d:\n", i);
		for(int j = 0;j<16;j++) {
			goal1 = j / 4;
			goal2 = j % 4;

			for(int k = 0;k<BASE_COUNT;k++) {
				if(k == 0) curr2 = numdat[i][k];
				if(k != 0) {curr1 = curr2; curr2 = numdat[i][k];}
				if((goal1 == curr1) && (goal2 == curr2)) result[i][j] = result[i][j] + 1;
			}


			if(goal1 == 0) printgoal1 = 'a';
                        if(goal1 == 1) printgoal1 = 't';
                        if(goal1 == 2) printgoal1 = 'c';
                        if(goal1 == 3) printgoal1 = 'g';
                        if(goal2 == 0) printgoal2 = 'a';
                        if(goal2 == 1) printgoal2 = 't';
                        if(goal2 == 2) printgoal2 = 'c';
                        if(goal2 == 3) printgoal2 = 'g';
			printf("| seq %c%c: %d | ", printgoal1, printgoal2, result[i][j]);
		}
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <time.h>
#include <Windows.h>
using namespace std;

int** m;
int** mo;
int** mnn;
int** myn;
int num;
int* vis;
int* visno;
queue <int> q;

void BFSD(int s) {
    vis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < num; i++) {
            if ((m[v][i] > 0) && (vis[i] > (vis[v] + m[v][i]))) {
                q.push(i);
                vis[i] = vis[v] + m[v][i];
            }
        }
    }
    printf("\nDists: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", vis[i]);
    }
}

void BFSDO(int s) {
    vis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < num; i++) {
            if ((mo[v][i] > 0) && (vis[i] > (vis[v] + mo[v][i]))) {
                q.push(i);
                vis[i] = vis[v] + mo[v][i];
            }
        }
    }
    printf("\nDists: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", vis[i]);
    }
}
void BFS(int s) {
    visno[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < num; i++) {
            if ((mnn[v][i] == 1) and (visno[i] == -1)) {
                q.push(i);
                visno[i] = visno[v] + 1;
            }
        }
    }
    printf("\nDists: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", visno[i]);
    }
}

void BFSO(int s) {
    visno[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        printf("%4i", v);
        for (int i = 0; i < num; i++) {
            if ((myn[v][i] == 1) and (visno[i] == -1)) {
                q.push(i);
                visno[i] = visno[v] + 1;
            }
        }
    }
    printf("\nDists: ");
    for (int i = 0; i < num; i++) {
        printf("%4i", visno[i]);
    }
}


int main(int argc, char * argv[])
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //generate array
	if(argc <= 2){
		printf("Params not found");
		return false;
	}else{
		printf("Params:\n");
		printf("Oriented: %s\n", argv[1]);
		printf("Weighted: %s\n", argv[2]);
	}
    int generate, choice;
    printf("Input array size: ");
    scanf("%i", &num);
    m = new int* [num];
    mo = new int* [num];
    mnn = new int* [num];
    myn = new int* [num];
    for (int i = 0; i < num; i++) {
        m[i] = new int[num];
        mo[i] = new int[num];
        mnn[i] = new int[num];
        myn[i] = new int[num];
    }
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                m[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 100;
                if (generate >= 30) {
                    m[i][j] = rand() % 100;
                }
                else {
                    m[i][j] = 0;
                }
            }
            else {
                m[i][j] = m[j][i];
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                mo[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 100;
                if (generate >= 30) {
                    mo[i][j] = rand() % 100;
                }
                else {
                    mo[i][j] = 0;
                }
            }
            else {
                generate = rand() % 100;
                if (generate >= 30) {
                    if (mo[j][i] == 0) {
                        int generate2 = rand() % 100;
                        if (generate2 >= 30) {
                            mo[i][j] = rand() % 100;
                        }
                        else {
                            mo[i][j] = 0;
                        }
                    }
                    else {
                        mo[i][j] = mo[j][i];
                    }
                }
                else {
                    mo[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                mnn[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 100;
                if (generate >= 30) {
                    mnn[i][j] = 1;
                }
                else {
                    mnn[i][j] = 0;
                }
            }
            else {
                mnn[i][j] = mnn[j][i];
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                myn[i][j] = 0;
            }
            else if (j > i) {
                generate = rand() % 100;
                if (generate >= 30) {
                    myn[i][j] = 1;
                }
                else {
                    myn[i][j] = 0;
                }
            }
            else {
                generate = rand() % 100;
                if (generate >= 30) {
                    if (myn[j][i] == 0) {
                        int generate2 = rand() % 100;
                        if (generate2 >= 30) {
                            myn[i][j] = 1;
                        }
                        else {
                            myn[i][j] = 0;
                        }
                    }
                    else {
                        myn[i][j] = myn[j][i];
                    }
                }
                else {
                    myn[i][j] = 0;
                }
            }
        }
    }
    //print array
    if ((*argv[1] == 'n') && (*argv[2] == 'y')) {
        printf("array:");
        for (int i = 0; i < num; i++) {
            printf("\n");
            for (int j = 0; j < num; j++) {
                printf("%4i", m[i][j]);
            }
        }
    }
    if ((*argv[1] == 'y') && (*argv[2] == 'y')) {
        printf("\n array:");
        for (int i = 0; i < num; i++) {
            printf("\n");
            for (int j = 0; j < num; j++) {
                printf("%4i", mo[i][j]);
            }
        }
    }
    if ((*argv[1] == 'n') && (*argv[2] == 'n')) {
        printf("\n array:");
        for (int i = 0; i < num; i++) {
            printf("\n");
            for (int j = 0; j < num; j++) {
                printf("%4i", mnn[i][j]);
            }
        }
    }
    if ((*argv[1] == 'y') && (*argv[2] == 'n')) {
        printf("\n array:");
        for (int i = 0; i < num; i++) {
            printf("\n");
            for (int j = 0; j < num; j++) {
                printf("%4i", myn[i][j]);
            }
        }
    }
    printf("\nInput start point: ");
    scanf("%i", &choice);
    //create arrays
    vis = new int[num];
    visno = new int[num];
    for (int i = 0; i < num; i++) {
        vis[i] = 1000;
        visno[i] = -1;
    }
    //result
	if((*argv[1] == 'n') && (*argv[2] == 'y')){
		printf("\nBFSD: ");
		BFSD(choice);
	}
	if((*argv[1] == 'y') && (*argv[2] == 'y')){
		printf("\nBFSDO: ");
		BFSDO(choice);
	}
    if ((*argv[1] == 'n') && (*argv[2] == 'n')) {
        printf("\nBFS: ");
        BFS(choice);
    }
    if ((*argv[1] == 'y') && (*argv[2] == 'n')) {
        printf("\nBFSO: ");
        BFSO(choice);
    }
}

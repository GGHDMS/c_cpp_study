#pragma once
// WGraphFloyd.h: Floyd �˰����� �ִ� ��� Ž�� ����� �߰��� �׷���
#include "WGraph.h"

class WGraphFloyd : public WGraph
{
	int	A[MAX_VTXS][MAX_VTXS];		// �ִܰ�� �Ÿ�
	int p[MAX_VTXS][MAX_VTXS];

public:
	void ShortestPathFloyd( ) { 
		for( int i=0 ; i<size ; i++ )
			for( int j=0 ; j<size ; j++ )
				A[i][j] = getEdge(i,j);

		for(int k=0 ; k<size ; k++ ){
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++)
					if (A[i][k] + A[k][j] < A[i][j]) {
						A[i][j] = A[i][k] + A[k][j];
						p[i][j] = k;
					}
				//printA( );
			}
		}
		//printA();
	}
	void pReset() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				p[i][j] = -1;
			}
		}
	}
	void printA() {
		printf("====================================\n");
		for( int i=0; i<size; i++){
			for(int j=0; j<size; j++) {
				if( A[i][j] == INF ) printf(" INF ");
				else printf("%4d ", A[i][j]);
			}
			printf("\n");
		}
	}
	void printPath(int start, int end) {
		if (p[start][end] != -1) {
			printPath(start, p[start][end]);
			printf("%s->", vertices[p[start][end]]);
			printPath(p[start][end], end);
		}
	}
}; 
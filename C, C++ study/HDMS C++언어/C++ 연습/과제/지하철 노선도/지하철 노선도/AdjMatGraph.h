#include <cstdio>
#include <cstring>
#define MAX_VTXS 256

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS][MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char* getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }
	
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}
	void insertVertex(const char *name) {
		if (!isFull())strcpy(vertices[size++],name);
		else printf("Error: 그래프 정점 개수 초과\n");
	}
	void gg() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(vertices[j], vertices[i]) == 0) {
					printf("%s", vertices);
				}
			}
		}
	}
	void insertEdge(int u, int v, int c) {
		setEdge(u, v, c);
		setEdge(v, u, c);
	}
	void display(FILE *fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; i++ ) {
			fprintf(fp, "%-25s", getVertex(i));
			for (int j = 0; j < size; j++) {
				fprintf(fp, " %3d", getEdge(i, j));
			}
			fprintf(fp, "\n");
		}
	}
	void change(const char *c1, const char *c2, int c) {
		int i;
		insertVertex(c2);
		for (i = 0; i < size; i++) {
			if (strcmp(vertices[i], c1) == 0) {
				break;
			}
		}
		insertEdge(size-1, i, c);
	}
	void p(const char*c, int k) {
		insertVertex(c);
		insertEdge(size - 1, size - 2, k);
	}

	void print(const char*c1) {
		int i;
		for (i = 0; i < size; i++) {
			if (strcmp(vertices[i], c1) == 0) {
				break;
			}
		}
		printf("%d\n", i);
	}
	void load(const char *filename) {
		FILE *fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[MAX_VTXS][MAX_VTXS];
				fscanf(fp, "%s ", str);
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					int val;
					fscanf(fp, "%d", &val);
					if (val != 0) {
						insertEdge(i, j, val);
					}
				}
			}
			fclose(fp);
		}
	}
	void store(const char *filename) {
		FILE *fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}
	void end() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (adj[i][j] != 11 && adj[i][j] != 12 && adj[i][j] != 13 && adj[i][j] != 14 && i != j ) {
					adj[i][j] = 9999;
				}
			}
		}
	}
};
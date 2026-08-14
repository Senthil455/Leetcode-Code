int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Hash map key for slope: (dy, dx)
typedef struct {
    int dy;
    int dx;
} Slope;

typedef struct {
    Slope key;
    int count;
} HashEntry;

#define MAX_HASH_SIZE 10007

int hash(Slope s) {
    return ((s.dy * 31 + s.dx) % MAX_HASH_SIZE + MAX_HASH_SIZE) % MAX_HASH_SIZE;
}

int equal(Slope a, Slope b) {
    return a.dy == b.dy && a.dx == b.dx;
}

void clearHashMap(HashEntry* map) {
    for (int i = 0; i < MAX_HASH_SIZE; i++) {
        map[i].count = 0;
        map[i].key.dy = 0;
        map[i].key.dx = 0;
    }
}

void insert(HashEntry* map, Slope s) {
    int idx = hash(s);
    while (map[idx].count != 0) {
        if (equal(map[idx].key, s)) {
            map[idx].count++;
            return;
        }
        idx = (idx + 1) % MAX_HASH_SIZE;
    }
    map[idx].key = s;
    map[idx].count = 1;
}

int getCount(HashEntry* map, Slope s) {
    int idx = hash(s);
    while (map[idx].count != 0) {
        if (equal(map[idx].key, s)) {
            return map[idx].count;
        }
        idx = (idx + 1) % MAX_HASH_SIZE;
    }
    return 0;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) return pointsSize;

    int result = 2;
    HashEntry hashMap[MAX_HASH_SIZE];

    for (int i = 0; i < pointsSize; i++) {
        clearHashMap(hashMap);
        int samePoint = 1;
        int sameX = 0;
        int localMax = 0;

        int x0 = points[i][0];
        int y0 = points[i][1];

        for (int j = i + 1; j < pointsSize; j++) {
            int x = points[j][0];
            int y = points[j][1];

            if (x == x0 && y == y0) {
                samePoint++;
            } else if (x == x0) {
                sameX++;
                localMax = sameX > localMax ? sameX : localMax;
            } else {
                int dx = x - x0;
                int dy = y - y0;
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                Slope slope = {dy, dx};
                insert(hashMap, slope);
                int count = getCount(hashMap, slope);
                localMax = count > localMax ? count : localMax;
            }
        }

        result = (localMax + samePoint) > result ? (localMax + samePoint) : result;
    }

    return result;
}
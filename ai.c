int reduce(int *a, int n, int (*select)(int, int))
{
    int result = a[0];

    for (int i = 1; i < n; ++i) {
        result = select(result, a[i]);
    }

    return result;
}

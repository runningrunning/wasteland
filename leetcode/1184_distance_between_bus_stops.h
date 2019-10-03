int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
{
    if (start == destination)
        return 0;

    int a = 0;
    for (int i = 0; i < distanceSize; i ++)
        a += distance[i];

    int s = start < destination ? start : destination;
    int d = start < destination ? destination : start;
    int c = 0;
    for (int i = s; i < d; i ++)
        c += distance[i];
    return c < (a - c) ? c : (a - c);
}

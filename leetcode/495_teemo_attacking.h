int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    if (!timeSeries || !timeSeriesSize || !duration)
        return 0;

     /* if 1, can not as attack at the same time */
     /*if (duration == 1)
         return timeSeriesSize;*/

    int* t = timeSeries;
    int all = 0;
    int s = t[0];
    duration --;
    int e = s + duration;

    for (int i = 0; i < timeSeriesSize; i ++)
    {
        if (t[i] <= e)
            e = t[i] + duration;
        else
        {
            all += e - s + 1;
            s = t[i];
            e = s + duration;
        }
    }
    all += e - s + 1;
    return all;
}

// O(nk) time
// SIMPLE IS FASTEST AND CORRECT !!!

// corner case, can be same value
// carefulness !!!!!!!!!!!!!!!!!!!! !!!!!
// STUPID error, careful !!!!!!!

// wrong code doesn't work, as it only calculate 2 values vmin, vmid, it could also
// vmax + cmin < vmid + cmid
// 2 16 8 17 15   2 and 8
// 7 3 8 11 13    3 and 7
// but as 7 and 2 are same index, then it will be 5, 13,
// but the correct answer is 5, 10

int minCostII(int** costs, int costsRowSize, int costsColSize)
{
    if (!costs || !costsRowSize || !costsColSize)
        return 0;

    if (costsColSize == 1)
        return costsRowSize == 1 ? costs[0][0] : 0;

    int cmin = INT_MAX;
    int cmin_i = 0;
    int cmid = INT_MAX;
    int cmid_i = 0;

    for (int i = 0; i < costsRowSize; i ++)
    {
        int* cs = costs[i];

        int vmin = INT_MAX;
        int vmid = INT_MAX;
        int vmin_i = 0;
        int vmid_i = 0;

        for (int j = 0; j < costsColSize; j ++)
        {
            int p = i ? (j == cmin_i ? cmid : cmin) : 0;

            if (cs[j] + p <= vmid)
            {
                if (cs[j] + p <= vmin)
                {
                    vmid = vmin;
                    vmid_i = vmin_i;
                    vmin = cs[j] + p;
                    vmin_i = j;
                }
                else
                {
                    vmid = cs[j] + p;
                    vmid_i = j;
                }
            }
        }

        cmin = vmin;
        cmid = vmid;
        cmin_i = vmin_i;
        cmid_i = vmid_i;
    }

    return cmin;
}



/* printf("%d : %d:%d %d:%d\n", i, cmin_i,cmin,cmid_i, cmid); */
//
/* for (int j = 0; j < costsColSize; j ++) */
/* { */
/*     if (cs[j] <= vmid) */
/*     { */
/*         if (cs[j] <= vmin) */
/*         { */
/*             vmid = vmin; */
/*             vmid_i = vmin_i; */
/*             vmin = cs[j]; */
/*             vmin_i = j; */
/*         } */
/*         else */
/*         { */
/*             vmid = cs[j]; */
/*             vmid_i = j; */
/*         } */
/*     } */
/* } */

/* printf("== %d : %d:%d %d:%d\n", i, vmin_i,vmin,vmid_i, vmid); */
/* if (vmin_i == cmin_i) */
/* { */
/*     vmin += cmid; */
/*     vmid += cmin; */

/*     if (vmin < vmid) */
/*     { */
/*         cmin_i = vmin_i; */
/*         cmid_i = vmid_i; */
/*         cmin = vmin; */
/*         cmid = vmid; */
/*     } */
/*     else */
/*     { */
/*         cmin_i = vmid_i; */
/*         cmid_i = vmin_i; */
/*         cmin = vmid; */
/*         cmid = vmin; */
/*     } */
/* } */
/* else */
/* { */
/*     if (vmid_i == cmin_i) */
/*         cmid += vmid; */
/*     else */
/*         cmid = cmin + vmid; */

/*     cmin_i = vmin_i; */
/*     cmid_i = vmid_i; */
/*     cmin += vmin; */
/* } */
/* printf("%d : %d:%d %d:%d\n", i, cmin_i,cmin,cmid_i, cmid); */

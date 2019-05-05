#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 100
char map[SIZE][SIZE];
char map0[SIZE][SIZE];
int  dst[SIZE][SIZE];
int  hp[SIZE][SIZE];
unsigned char moved[SIZE][SIZE];
int maxx,maxy;

int calc(int,int);

int main(int argc, char **argv) {
    int n;
    int eap;
    maxx=maxy=0;
    while (1) {
        if (fgets(&map0[maxy][0],SIZE,stdin)==0) break;
        n=strlen(map0[maxy]);
        if (n<2) break;
        if (map0[maxy][n-1]=='\n') n--;
        map0[maxy][n]=0;
        maxy++;
        if (n>maxx) maxx=n;
    }
    if (argc==2) eap=atoi(argv[1]);
    else for (eap=3; calc(eap,0)<0; eap++) { }
    calc(eap,1);
    return 0;
}

int calc(int eap, int verbose) {
    int t;
    int x,y;
    int i,j;
    int tx,ty;
    int d;
    int E=0,G=0;
    int ok;
    int thp=0;
    char cur, enemy;
    memcpy(map,map0,sizeof map);

    for (y=0; y<maxx; y++) {
        for (x=0; x<maxx; x++) {
            if (map[y][x]=='G') {G++; hp[y][x]=200;}
            else if (map[y][x]=='E') {E++; hp[y][x]=200;}
        }
    }

    t=0;
    while (1) {
        memset (moved,0,sizeof moved);
        for (y=0; y<maxx; y++) {
            for (x=0; x<maxx; x++) {
                if (moved[y][x]) continue;
                if (map[y][x]=='G' || map[y][x]=='E') {
                    cur=map[j=y][i=x];
                    enemy=cur^'G'^'E';
                    if ((enemy=='E' && !E) || (enemy=='G' && !G)) goto endgame;
                    /* area must be surrounded by walls so this is not an edge */
                    if (map[y-1][x]!=enemy && map[y][x-1]!=enemy && map[y][x+1]!=enemy && map[y+1][x]!=enemy) {
                        /* must first seach for a target because in case of a
                           tie, the correct target must be chosen.  A valid
                           target is a space adjacent to an enemy. */
                        memset(dst,0,sizeof dst);
                        dst[y][x]=1;
                        d=1;
                        do {
                            ok=0;
                            for (j=0; ok>=0 && j<maxy; j++) {
                                for (i=0; ok>=0 && i<maxy; i++) {
                                    if (dst[j][i]==0
                                    && map[j][i]=='.'
                                    && (dst[j-1][i]==d || dst[j][i-1]==d || dst[j][i+1]==d || dst[j+1][i]==d)
                                    ) {
                                        dst[j][i]=d+1;
                                        /* if this square is a valid target location then it is necessarily
                                           the correct one because of the order in which the search is performed. */
                                        if (map[j-1][i]==enemy || map[j][i-1]==enemy || map[j][i+1]==enemy || map[j+1][i]==enemy) ok=-1;
                                        else ok=1;
                                    }
                                }
                            }
                            d++;
                        } while (ok>0);
                        if (!ok) continue;
                        /* Target found but i,j were incremented at the ends of the loops.
                           In theory we can backtrack to find a route, but if there is a
                           choice of routes that might not find the correct one.  Instead
                           start a new seach for the shortest route to this target. */
                        memset(dst,0,sizeof dst);
                        dst[--j][--i]=1;
                        d=1;
                        while (ok && dst[y][x]==0) {
                            ok=0;
                            for (j=0; j<maxy; j++) {
                                for (i=0; i<maxy; i++) {
                                    if (dst[j][i]==0 
                                    && (map[j][i]=='.' || (j==y && i==x))
                                    && (dst[j-1][i]==d || dst[j][i-1]==d || dst[j][i+1]==d || dst[j+1][i]==d)
                                    ) ok=dst[j][i]=d+1;
                                }
                            }
                            d++;
                        } 
                        if (ok) { /* should always be true because we knew the target was reachable */
                            d--;
                            if (dst[j=y-1][i=x]==d || dst[++j][--i]==d || dst[j][i+=2]==d || dst[++j][--i]==d) {
                                map[j][i]=map[y][x];
                                map[y][x]='.';
                                hp[j][i]=hp[y][x];
                                hp[y][x]=0;
                            }
                        }
                        else continue;
                    }
                    /* [j][i] is the new location, or it didn't move and [j][i] is the current location */
                    /* If no target was reachable, control doesn't reach here - but moved[j][i] only
                       actually matters if j>y or i>x. */
                    moved[j][i]=1;
                    d=9999; /* find minimum hit points amongst adjacent enemies */
                    if (map[j-1][i]==enemy) d=hp[ty=j-1][tx=i];
                    if (map[j][i-1]==enemy && hp[j][i-1]<d) d=hp[ty=j][tx=i-1];
                    if (map[j][i+1]==enemy && hp[j][i+1]<d) d=hp[ty=j][tx=i+1];
                    if (map[j+1][i]==enemy && hp[j+1][i]<d) d=hp[ty=j+1][tx=i];
                    if (d<9999) {
                        hp[ty][tx] -= (cur=='E'?eap:3);
                        if (hp[ty][tx]<=0) {
                            hp[ty][tx]=0;
                            map[ty][tx]='.';
                            if (enemy=='E') E--; else G--;
                            if (enemy=='E' && !verbose) return -1;
                        }
                    }
                }
            }
        }
        t++;
        if (verbose) {
            printf("%d\n",t);
            for (y=0; y<maxy; y++) {
                fputs(map[y],stdout);
                for (x=0; x<maxx; x++) {
                    if (map[y][x]=='G' || map[y][x]=='E') printf(" %c(%d)",map[y][x],hp[y][x]);
                }
                putchar('\n');
            }
            putchar('\n');
        }
    }
    endgame:
    if (verbose) {
            printf("%d\n",t);
            for (y=0; y<maxy; y++) {
                fputs(map[y],stdout);
                for (x=0; x<maxx; x++) {
                    if (map[y][x]=='G' || map[y][x]=='E') printf(" %c(%d)",map[y][x],hp[y][x]);
                }
                putchar('\n');
            }
            putchar('\n');
    }
    printf("EAP=%d Rounds=%d\n",eap,t);
    thp=0;
    for (y=0; y<maxy; y++) {
        for (x=0; x<maxx; x++) {
            if (map[y][x]=='E' || map[y][x]=='G') thp+=hp[y][x];
        }
    }
    printf("HP=%d\n",thp);
    printf("Ans=%d\n",thp*t);
    return (E>0)-(G>0);
}

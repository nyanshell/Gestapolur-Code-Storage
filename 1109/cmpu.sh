    ./gen > u303.in
    ./3033 < u303.in > ou1.out
    ./cmp < u303.in > ou2.out
while ["`diff ou1.out ou2.out`"  == ""]
do
    ./gen > u303.in
    ./3033 < u303.in > ou1.out
    ./cmp < u303.in > ou2.out
done
./whug < whug.in > whug0.out
if [ "`diff whug.out whug0.out `" != "" ] ; then
    echo "WRONG ANSWER"
else
    echo "ACCEPTED"
fi
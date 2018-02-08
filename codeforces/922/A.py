c,o = map(int, raw_input().split())

if (c,o) == (0,1):
    print "Yes"
elif o <= 1:
    print "No"
elif o > c+1:
    print "No"
else:
    if (c-o+2)%2 == 1:
        print "Yes"
    else:
        print "No"

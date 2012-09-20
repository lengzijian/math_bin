import math_bin


###################################################btod
print "btod :    '111111'---->?"
print math_bin.btod('111111')

###################################################dtob
print "---------------------------------"

str = '000000'
one_num = math_bin.dtob(15,len(str),str)
print "dtob :    the number of '1'"
print one_num
print "'15'-------->?"
print str


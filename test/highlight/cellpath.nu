$.foo."bar"
# <- punctuation.special
#  ^ variable.parameter
#    ^ punctuation.delimiter
#     ^ string

ls | where name?! =~ 'a'
#            ^ variable.parameter
#              ^ punctuation.delimiter
#               ^ punctuation.delimiter

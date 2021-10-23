def remove(msg,target):                 #function defination
    for i in msg:
        if i in target:
            msg=msg.replace(target,'')
    return msg
    
    
msg=input('enter the message: ')        #driver program
target=input('enter character to be removed: ')
ans=remove(msg,target)
print(ans)

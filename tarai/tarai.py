import time

def Tarai(x,y,z):
    if(x <= y):
        return y
    else:
        return Tarai(Tarai(x-1,y,z),Tarai(y-1,z,x),Tarai(z-1,x,y))

start = time.time()

Tarai(13,5,0)

end = time.time() - start

print(end)

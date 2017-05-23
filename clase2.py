from mpi4py import MPI
comm = MPI.COM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()
root = 0
l=[]
l1=[]

if rank == root:
    for i in range(10):
        l[i] = i +1

l1 = comm.bcast(l,root = root)
print l1

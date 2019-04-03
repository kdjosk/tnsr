# tnsr
This is a simple tensor calculator, that can operate on tensors of different ranks and dimensions, and perform operations such as addition or multiplication.
## Operations

- `create <string name> <int dimension> <int rank>` add a tensor of given name, dimension and rank to the workspace
- `create_init <string name> <int dimension> <int rank> <int values[]>` same as above but initialize the values of the tensor
- `list` lists all of the tensors in the workspace
- `alg <Tensor res> = <Tensor t1> x <Tensor t2>` multiply t1 and t2 element by element (thus they have to have the same rank and dimension) and assign the result to res (with `alg` operations if res isn't yet present in the workspace it will be created)
- `alg <Tensor res> = <Tensor t1> * <int k>` multiply t1 by a constant k and assign the result to result to res
- `alg <Tensor res> = <Tensor t1> + <Tensor t2>` add t1 and t2 and assign the result to res
- `get <Tensor t> <int coordinates[]>` return value of t at given coordinates, e.g. if tensor is of rank 2 the coordinates are column and row (first x then y).
- `hello` yes

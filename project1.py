class Matrix(object):

    def __init__(self, L):
        self.a = float(L[0][0])
        self.b = float(L[0][1])
        self.c = float(L[1][0])
        self.d = float(L[1][1])

    def __str__(self):
        return "[%f,%f]\n[%f,%f]" %(self.a,self.b,self.c,self.d)

    def determinant(self):
        return self.a*self.b-self.c*self.d

    def trace(self):
        return self.a + self.d

    def inverse(self):
        D = self.determinant()
        if D == 0.0:
            return "Matrix is singular"
        else:
            return Matrix([[self.d/D,-self.b/D],[-self.c/D, self.a/D]])

    def characterisitc_polynomial(self):
        return 'x^2- %f * x + %f'%(self.trace(),self.determinant())

    def matrix_product(self,other):
        return Matrix([[self.a*other.a+self.b*other.c,self.a*other.b+self.b*other.d],[self.c*other.a+self.d*other.c,self.c*other.b+self.d*other.d]])

def main():
    A = Matrix([[1,2],[3,4]])
    B = Matrix([[2,3], [4, 5]])
    print(A.determinant())
    print(A.trace())
    print(A.inverse())
    print(A.characterisitc_polynomial())
    print(A.matrix_product(B))

main()

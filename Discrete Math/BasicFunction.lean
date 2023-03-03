namespace BasicFunctions

#eval 5%3
#eval 2^3

def testFunction x := x*x +3
def result := testFunction 3
#eval println! "The result is {result}"

--define (argument:type)
def testFunction2 (x:Nat) := 2*x^2 - x + 3
def result2 := testFunction2 (3+7)
#eval println! "{result2}"

def testFunction3 (x:Int) :=
  if x > 100 then
    2*x^2 - x + 3
  else
    2*x^2 + x -37
#eval println! "{testFunction3 101}"

end BasicFunctions
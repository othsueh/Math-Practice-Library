-- Define some constants 
def m : Nat := 1
def n : Nat := 0
def a : Bool := true
def b : Bool := false
-- Check the types 
#check m
#check n + 0
#check a && b
#check a || b
#check true
#check -35
#check 35
#check 35.5
#check 3.5e4
-- Evaluate
#eval a || b
#eval a && b

-- notation
#check Nat → Nat
#check Nat -> Nat
#check Nat × Nat
#check Prod Nat Nat
#check Nat → Nat → Nat
#check (Nat → Nat) → Nat
#check Nat.succ
#check Nat.add
#eval Nat.add 5 (Nat.add 4 3)
#eval Nat.succ 100
#eval (5,0).1
#eval (5,0).2
namespace morefunctions
#eval println! "Hello World!"

def twice (f : Nat -> Nat) (a : Nat) := f (f a)
#eval twice (fun x => x*2+3) 23

theorem twiceAdd2 (a:Nat) : twice (fun x => x+2) a = a+4 := 
  rfl

#eval twice (. + 2) 10

inductive Weekday where 
  | sunday : Weekday
  | saturday : Weekday
  | monday    : Weekday
  | tuesday   : Weekday
  | wednesday : Weekday
  | thursday  : Weekday
  | friday    : Weekday

#check Weekday.sunday
#check Weekday.saturday

open Weekday
#check sunday
   
def NatofWeekday (d: Weekday) : Nat :=
  match d with
  | sunday => 1 
  | saturday => 7 
  | monday    => 2
  | tuesday   => 3
  | wednesday => 4
  | thursday  => 5
  | friday    => 6

#eval NatofWeekday saturday

def Issunday : Weekday -> Bool := 
  fun 
  | sunday => true
  | _ => false

#eval Issunday saturday
#eval Issunday sunday

#eval toString 10
#eval toString (10,20)

instance : ToString Weekday where toString (d:Weekday) : String := 
  match d with
  | sunday => "Sunday"
  | saturday => "Saturday"
  | monday    => "Monday"
  | tuesday   => "Tuesday"
  | wednesday => "Wednesday"
  | thursday  => "Thursday"
  | friday    => "Friday"

#eval toString sunday

def Weekday.next (d: Weekday) : Weekday :=
  match d with
  | sunday    => monday
  | monday    => tuesday
  | tuesday   => wednesday
  | wednesday => thursday
  | thursday  => friday
  | friday    => saturday
  | saturday  => sunday

#eval Weekday.next sunday
#eval next wednesday

def Weekday.previous : Weekday -> Weekday
  | sunday    => saturday
  | monday    => sunday
  | tuesday   => monday
  | wednesday => tuesday
  | thursday  => wednesday
  | friday    => thursday
  | saturday  => friday

#eval toString (next (previous wednesday))

theorem Weekday.nextOfPrevious (d:Weekday) : next (previous d) = d := by 
  cases d
  all_goals rfl

end morefunctions
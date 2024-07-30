/*
Description:
I have given two arrays, time and direction.
time[i] = arrival time of the student at the gate.
direction[i] = direction of the student (either 1 for exit 0 for entrance)
There is one queue for the entrance and one queue for the exit, all the students line-up based on their respective direction.
Each student will take 1 second for crossing the gate.
Constraints:
-time[i] <= time[i+1]
-In case there are two students at the gate at the same time.
1)If both the students are waiting in the same line, the first student which arrived first will leave first, based on index
2)If both the students are from the different line
--If the gate was used at time t - 1 for entrance, then entry queue will be preferred.
--Else If the gate was used at time t - 1 for exit, then exit queue will be preferred.
--Else if the gate wasn't used at time t-1, exit queue will be preferred.

I need to return the time at which each student will get the change to cross the gate.
*/
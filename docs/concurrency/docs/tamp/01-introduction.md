# 1. Introduction

Tow kinds of communication occur naturally in concurrent systems:

- **Transient** communication requires both parties to pariticipate at the same time. Shouting, gestures, or cell phone calls are examples of transient communication.
- **Persistent** communication allows the sender and receiver to participate at different times. Posting letters, sending email, or leaving notes under rock are all examples of persistent communication.

## mutual exclusion protocol

Background: <br/>
Alice and Bob are neighbors, and they share a yard.<br/>
Alice owns a cat and Bob owns a dog.<br/>
Both pets like to run around in the yard, but they do not get along.<br/>
Alice and Bob agree that they should **coordinate** to make sure that both pets are never in the yard at the same time.

Alice and Bob each sets up a flag pole.

When Alice wants to release her cat:

1. She raises her flag.
2. When Bob's flag is lowered, she unleashes her cat.
3. When her cat comes back, she lowers her flag.

Bob's behavior:

1. He raises his flag.
2. When Alice's flag is raised:<br/>
   a) Bob lowers his flag.<br/>
   b) Bob **waits** until Alice's flag is lowered.<br/>
   c) Bob raises his flag.<br/>
3. As soon as his flag is raised and hers is down, he unleashes his dog.
4. When his dog comes back, he lowers his flag.

> flag principle

If Alice and Bob each

1. raises his or her own flag, and then
2. looks at the other's flag,

then at least one will see the other's flag raised, and will not let his or her pet enter the yard.

## producer-consumer protocol

Background:<br/>
Alice got custody of the pets, Bob needs to feed them.<br/>
The pets now get aloing with each ohter, but they side with Alice, and attack Bob whenever they see him.<br/>
Alice and Bob need to devise a protocl for Bob to deliver food to the pets withoud Bob and the pets being in the yard together.<br/>
The protocol should not waste anyone's time: Alice does not want to release her pets into the yard unless there is food thers, and Bob does not want to enter the yard unless the pets have consumed all the food.

the cans-and-string protocol:

Bob places a can standing up on Alice's windowsill, ties one end of his string around the can, and puts the other end of the string in his living room. He then puts food in the yard and knocks the can down.

From now on, When Alice wants to release the pets:

1. She waits until the can is down.
2. She releases the pets.
3. When the pets return, Alice checks whether they finished the food. If so, she reset the can.

Bob:

1. He **waits** until the can is up.
2. He puts food in the yard.
3. He pulls the string and knocks the can down.

## Amdahl's Law

Let $p$ be the fraction of the job that can be executed in parallel, and assume that it takes normalized time $1$ for a single processor to complete the job.

With $n$ concurrent processors, the parallel part takes time $\frac{p}{n}$ and the sequential part take time $1-p$, so the **speedup** $S$ of a job, that is, the ratio between the sequential single-processor time and the parallel time is 

$$
S = \frac{1}{1-p+\frac{p}{n}}
$$


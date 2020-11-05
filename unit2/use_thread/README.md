# Use exit:

To understand the real purpose of pthread_exit. As you can see, there are multiple pthread_exit code. 
You try and Following are the result do you observe ?:

- Exit 1: 42
- Exit 2: 42
- Exit 3: thread failed
- Exit 4: error
- Exit 5: 42
- Without a pthread_exit statement: 42

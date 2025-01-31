# Discussion

- **Solution**: I used line-by-line processing to handle large log files efficiently. C++ allows for more fine-grained control over system resources, such as file handling and memory, which is essential for handling a 1 TB log file.

## Summary
The final solution processes the log file line-by-line and filters out the logs that match the given date. It writes the matching logs to a new output file. This method ensures that we only load relevant data into memory, allowing the program to handle large files efficiently.
# Job_Sequence_with_deadline.py

def Job_Sequence_with_deadline(Jobs, n):
    
    """""
    This function takes a list of jobs with their deadline and profit and returns the schedule of jobs to maximize the profit.
    Jobs are sorted in descending order of profit.

    Parameters:
    Jobs: list of jobs with their deadline and profit
    n: number of jobs

    Output:
    schedule: list of jobs scheduled to maximize the profit
    """""

    Jobs.sort(reverse=True, key=lambda x: x[2])

    max_deadline = max(Jobs, key=lambda x: x[1])[1]

    schedule = [0] * max_deadline

    for i in range(n):
        for j in range(Jobs[i][1] - 1, -1, -1):
            if schedule[j] == 0:
                schedule[j] = Jobs[i][0]
                # print(f"Job {Jobs[i][0]} is added to the schedule at position {j + 1}")
                break

    return schedule


# Job consists of : Job number , deadline, profit
Jobs = [['J1', 2, 100], ['J2', 1, 19], ['J3', 2, 27], ['J4', 1, 25], ['J5', 3, 15]]

schedule = Job_Sequence_with_deadline(Jobs, len(Jobs))
print("Final schedule:", schedule)


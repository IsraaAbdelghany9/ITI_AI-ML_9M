from tabulate import tabulate

table = [["Sun",696000,1989100000],["Earth",6371,5973.6],
         ["Moon",1737,73.5],["Mars",3390,641.85]]

print(tabulate(table))


import emoji
print(emoji.emojize('Python is :thumbs_up:'))

print(emoji.emojize('Python is :thumbsup:', language='alias'))

print(emoji.demojize('Python is ' + emoji.emojize(':thumbs_up:')))

print(emoji.emojize("Python is fun :red_heart:"))

print(emoji.emojize("Python is fun :red_heart:", variant="emoji_type"))

print(emoji.is_emoji("👍"))

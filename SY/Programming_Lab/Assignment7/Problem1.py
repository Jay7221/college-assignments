total_population = 80000
percent_men = 52 / 100
literacy = 48 / 100
literacy_men = 35 / 100

percent_women = 1 - percent_men
number_men = percent_men * total_population
number_women = percent_women * total_population
total_literate = literacy * total_population
literate_men = literacy_men * number_men
literate_women = total_literate - literate_men
illiterate_men = number_men - literate_men
illiterate_women = number_women - literate_women

print("The number of illiterate men is : %d, and illiterate women is : %d"%
      (illiterate_men, illiterate_women))

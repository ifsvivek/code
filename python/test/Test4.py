def count_occurrences(data_list):
  """
  This function counts the occurrences of each object in a list.

  Args:
      data_list: A list of any data type.

  Returns:
      A dictionary where keys are unique objects from the list and values are their counts.
  """
  occurrences = {}
  for item in data_list:
    if item in occurrences:
      occurrences[item] += 1
    else:
      occurrences[item] = 1
  return occurrences

# Example usage
my_list = ["apple", "banana", "apple", "orange", "banana", "cherry"]
occurrence_dict = count_occurrences(my_list)

print(occurrence_dict)

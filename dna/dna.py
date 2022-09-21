import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    # Read database file into a variable
    individuals = []

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        list_reader = list(reader)
        list_sequence = list(list_reader[0].keys())

        for i in list_reader:
            for STR in list_sequence[1:]:
                i[STR] = int(i[STR])
            individuals.append(i)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    dict_sequence = dict()
    for STR in list_sequence[1:]:
        dict_sequence[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    match = 0
    for profile in individuals:
        for STR in list_sequence[1:]:
            if profile[STR] == dict_sequence[STR]:
                match = 1
                match_name = profile['name']
            else:
                match = 0
                break
        if match == 1:
            print(match_name)
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()

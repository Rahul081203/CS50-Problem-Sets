#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int m = 0 ; m < candidate_count ; m++)
    {
        if (strcmp(candidates[m].name, name) == 0)
        {
            candidates[m].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Implementing Bubble Sort to arrange the votes in order and find the winner //
    for (int k = 0 ; k <= candidate_count - 2 ; k++)
    {
        if (candidates[k].votes > candidates[k + 1].votes)
        {
            candidate temp = candidates[k];
            candidates[k] = candidates[k + 1];
            candidates[k + 1] = temp;
        }
    }
    printf("%s\n",candidates[candidate_count-1].name);
    for(int x = candidate_count - 2 ; x >= 0 ; x--)
    {
        if(candidates[x].votes == candidates[candidate_count - 1].votes)
        {
            printf("%s\n",candidates[x].name);
        }
    }

    return;
}
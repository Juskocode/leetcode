#!/bin/bash

# Check if category and problem name are provided
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Usage: $0 <category> <problem_name>"
  exit 1
fi

CATEGORY="$1"
PROBLEM_NAME="$2"
PROBLEM_STATEMENT_PATH="problems/$CATEGORY/$PROBLEM_NAME.md"

# Find the solution file with any extension in the solutions directory under the specified category
SOLUTION_PATH="solutions/$CATEGORY/$PROBLEM_NAME.*"

# Check if problem statement file exists
if [ ! -f "$PROBLEM_STATEMENT_PATH" ]; then
  echo "Problem statement not found: $PROBLEM_STATEMENT_PATH"
  exit 1
fi

# Check if solution file exists
if [ -z "$SOLUTION_PATH" ]; then
  echo "Solution file not found for problem: $SOLUTION_PATH"
  exit 1
fi

# Add files to Git
git add "$PROBLEM_STATEMENT_PATH" "$SOLUTION_PATH"

# Commit with a message
git commit -m "Add solution for '$CATEGORY/$PROBLEM_NAME'"

# Push to the remote repository
git push origin main  # Replace 'main' with the branch name if different

echo "Successfully pushed '$CATEGORY/$PROBLEM_NAME' to GitHub."


# Lab 9: Programming with AI Assistance

This lab focuses on **programming with AI assistance** and how tools like GitHub Copilot can support typical software development workflows.

You will practice the following concepts:

* Setting up GitHub Copilot in Visual Studio Code
* Using AI for code documentation
* Using AI for code explanation and error analysis
* Using AI for refactoring
* Using AI for unit-test generation
* Using AI for boilerplate generation

The goal of this lab is not to let the AI solve everything for you. The goal is to learn how to use AI as a development assistant while still keeping responsibility for correctness, architecture, code quality, and understanding.

All the following sections of this lab are based on the following levels of difficulty:

🟢 __Simple__: A simple task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it.

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: Set Up GitHub Copilot in Visual Studio Code

GitHub Copilot is an AI coding assistant that can be used directly inside Visual Studio Code. It can suggest code while you type, answer questions about code, explain errors, generate tests, and propose code changes.

GitHub Copilot Free can currently be used without a paid subscription. The free tier is limited, but sufficient for this lab. At the time of writing, GitHub lists **2,000 completions per month** and **50 chat or agent requests per month** for the free plan.

**NOTE**: You are free to use any AI coding assistant such as Claude Code, Cursor, or Continue with Ollama.

---

### Task Description

Set up GitHub Copilot in Visual Studio Code and verify that it works.

### Step 1: Check the Prerequisites

You need:

* Visual Studio Code installed
* A GitHub account
* Internet access
* Access to GitHub Copilot Free or another Copilot plan

---

### Step 2: Install the GitHub Copilot Extension

1. Open Visual Studio Code.
2. Open the Extensions view.

3. Search for:

   ```text
   GitHub Copilot
   ```

4. Install the official extension published by GitHub.
5. Also install the Copilot Chat functionality if VS Code asks for it or by just searching for the extension

   ```text
   GitHub Copilot Chat
   ```

---

### Step 3: Sign In with GitHub

1. Click the GitHub Copilot icon in the VS Code status bar or activity bar.
2. Select the option to sign in.
3. A browser window opens.
4. Sign in with your GitHub account.
5. Authorize Visual Studio Code to use GitHub Copilot.
6. Return to VS Code.

After sign-in, VS Code should show that Copilot is enabled.

---

### Step 5: Verify Inline Suggestions

Create a new file:

```text
copilot_test.cpp
```

Insert the following comment:

```cpp
// Create a function that returns the maximum of two integers
```

Then press Enter and wait shortly. Copilot should suggest a function implementation.

Accept a suggestion with:

```text
Tab
```

Depending on your internet connection, the suggstion might take some seconds to pop-up.
However, you can see if Copilot is processing something in the background on the Copilot icon with some loading shape.

If no suggestion appears, check:

* Are you signed in to GitHub?
* Is the GitHub Copilot extension enabled?
* Is the file recognized as C++?
* Is Copilot enabled in the status bar?

---

### Step 6: Verify Copilot Chat

Open Copilot Chat in VS Code via:

```text
Keyboard Shortcut: Ctrl + Alt + I or for macOS: Cmd + Ctrl + I
```
or
```text
Command Palette: Ctrl + Shift + P then type Chat: Open Chat
```
or by clicking on the icon on the top right called ```Toggle Secondary Side Bar```

Then ask:

```text
Explain the difference between a pointer and a reference in C++.
```

Read the answer critically. It should be technically correct and understandable.


## 🟢 Section II: AI-Assisted Documentation with Doxygen

AI is especially useful for documentation tasks because it can generate structured and readable first drafts very quickly. However, AI-generated documentation must still be checked carefully because it can describe behavior that the code does not actually implement.

---

### Task Description

Create a file:

```text
statistics.hpp
```

Add the following function declarations:

```cpp
double calculate_average(const std::vector<int>& values);

double calculate_median(std::vector<int> values);

int count_values_in_range(
    const std::vector<int>& values,
    int minimum,
    int maximum);
```

Create a second file:

```text
statistics.cpp
```

Implement all three functions yourself.

Requirements:

* Throw `std::invalid_argument` if the vector is empty
* Use `const` where appropriate
* Avoid magic numbers
* contain at least one test call per function in main

Then use GitHub Copilot Chat or inline prompting to:

* generate Doxygen comments for all functions
* generate additional comments inside the .cpp file where useful

Fell free to use different prompts for different outputs.

---

### Required Result

Inspect the generated comments carefully and answer the following questions as comments in your code:

* What was/were your prompt(s)? Write them down.
* Did the AI generate unnecessary comments?
* Did the AI explain obvious code? Which comments were actually useful?
* Did the AI generate technically incorrect documentation?
* Did the AI mention exceptions or edge cases that do not exist?
* Would you keep all generated comments in a professional project or did you manually change something in the documentation?
* If you used different prompts: Did AI perform better for some prompts? 

---

## 🟢 Section III: AI-Assisted Code Explanation

AI can help explain existing code. This is useful when working with unfamiliar code, legacy code, or code written by another developer. However, the explanation must always be compared with the actual implementation.

---

### Task Description

Use your files from the previous section II and extend them with:

```cpp

int count_even_numbers(const std::vector<int>& values)
{
    int counter = 0;

    for (int value : values)
    {
        if (value % 2 == 0)
        {
            ++counter;
        }
    }

    return counter;
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::cout << count_even_numbers(numbers) << std::endl;
    return 0;
}
```

Use Copilot Chat to answer the following prompts:

```text
Explain what this code does step by step.
```

```text
Which edge cases should be tested for this function?
```

```text
Can this function be improved? If yes, how?
```

---

### Required Result

Create a file:

```text
section_3_code_explanation.md
```

Document for each prompt you used:

* the most important points from Copilot's explanation
* whether the explanation was correct
* at least two edge cases suggested by Copilot
* one improvement suggestion and whether you agree with it

---

## 🟢 Section IV: AI-Assisted Error Analysis

AI is often helpful when compiler errors, linker errors, runtime errors, stack traces, or CI/CD logs are long and difficult to read. The AI should be treated as a debugging assistant that proposes hypotheses, not as an authority.

---

### Task Description

Use the file in this folder called:

```text
broken_sensor.cpp
```

Then:
* Copy the file and call it **broken_sensor_myFix.cpp**
* Prepare a clock and start the timer:
* Try to compile the file e.g. via:
```bash
g++ -std=c++20 -Wall -Wextra -pedantic broken_sensor_myFix.cpp -o broken_sensor_myFix
```
* You will get some error messages. Try to fix the code by yourself. DO NOT USE AI OR ANY HELP!
* Note down which changes you made e.g. as comments.
* If you think you got every error, compile it again and check it.
* Repeat the process until you found all the errors or if you are out of ideas.
* Then stop your timer and write down how much time you spent.

Afterwards:
* Copy the file ```broken_sensor.cpp``` and call it **broken_sensor_aiFix.cpp**
* Prepare a clock and start the timer:
* Try to compile the file e.g. via:
```bash
g++ -std=c++20 -Wall -Wextra -pedantic broken_sensor_myFix.cpp -o broken_sensor_myFix
```
* You will get some error messages. Try to fix the code by using a Chat Bot e.g. Copilot Chat.
* Note down which changes you made e.g. as comments.
* If you think you got every error, compile it again and check it.
* Repeat the process until you found all the errors or if AI repeats itself.
* Then stop your timer and write down how much time you spent.

---

### Required Results

Submit:

* Compare how much time you spent and the result (i.e. found all errors) with the result and time when using AI
* Was AI able to find all the bugs?
* Was there something that AI had some troubles with?

---

## 🟡 Section V: AI-Assisted Refactoring

Refactoring means improving the internal structure of existing code without changing its externally visible behavior. AI can suggest useful refactorings, but every change must be reviewed carefully because behavior can accidentally change.

---

### Task Description

Create a file:

```text
temperature_report.cpp
```

Insert the following code:

```cpp
#include <iostream>
#include <vector>

void print_temperature_report(const std::vector<double>& temperatures)
{
    double sum = 0.0;
    double min = temperatures[0];
    double max = temperatures[0];

    for (double temperature : temperatures)
    {
        sum += temperature;

        if (temperature < min)
        {
            min = temperature;
        }

        if (temperature > max)
        {
            max = temperature;
        }
    }

    double average = sum / temperatures.size();

    std::cout << "Average: " << average << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Maximum: " << max << std::endl;
}

int main()
{
    std::vector<double> temperatures = {18.5, 20.0, 19.5, 21.0};
    print_temperature_report(temperatures);
    return 0;
}
```

Ask Copilot to refactor the code.

Use prompts like:

```text
Refactor this code to improve readability and separation of concerns. Do not change the observable behavior.
```

```text
Extract suitable helper functions and add basic error handling for an empty vector.
```

Review the proposal carefully and apply only changes that you understand.

---

### Requirements

Your final code should:

* avoid duplicated logic
* handle an empty vector safely
* separate calculation from output
* use meaningful function names
* use `const` where appropriate

---

### Required Result

Submit:

* the refactored `temperature_report.cpp`
* a file `section_5_refactoring.md` answering:

```text
1. Which refactorings did Copilot suggest?
2. Which suggestions did you accept?
3. Which suggestions did you reject?
4. Did the behavior of the program change?
5. How did you verify that the refactoring was correct?
```

---

## 🟡 Section VI: AI-Assisted Unit-Test Generation

AI can generate unit tests quickly. This is useful for improving test coverage and discovering edge cases. However, AI-generated tests are often too shallow, redundant, or focused on implementation details instead of behavior.

---

### Task Description

Reuse your files from Section II:

* `statistics.hpp`
* `statistics.cpp`

Ask Copilot to generate tests for `calculate_average`.

Use a prompt like:

```text
Generate simple C++ unit tests for calculate_average. Include normal cases, edge cases, and exception tests. Use assert instead of a test framework.
```

Create a file:

```text
statistics_test.cpp
```

The tests should cover at least:

* average of positive values
* average of negative values
* average of mixed positive and negative values
* vector with one value
* empty vector throws an exception

Compile and run your tests.

Example command:

```bash
g++ -std=c++20 -Wall -Wextra -pedantic statistics.cpp statistics_test.cpp -o statistics_test
./statistics_test
```

---

### Required Result

Submit:

* `statistics_test.cpp`
* a file `section_6_unit_tests.md` answering:

```text
1. Which test cases did Copilot generate?
2. Which important test cases were missing?
3. Did you modify the generated tests?
4. Did all tests pass?
5. Why should AI-generated tests be reviewed manually?
```

---

## 🔴 Section VII: AI-Assisted Boilerplate Generation for a Small Class Design

Boilerplate code is repetitive, standardized code that is necessary but often not conceptually difficult. AI can generate boilerplate efficiently, for example class skeletons, constructors, getters, simple method bodies, and file headers.

---

### Task Description

Use Copilot to generate the boilerplate for a small C++ class design.

You want to model simple sensors in a monitoring system.

Create the following files:

```text
sensor.hpp
sensor.cpp
temperature_sensor.hpp
temperature_sensor.cpp
main.cpp
```

The design should contain:

* a base class `Sensor`
* a derived class `TemperatureSensor`
* a sensor name
* a virtual method `read_value()`
* a method to print a short sensor report
* Doxygen comments for all public classes and methods

Use Copilot for boilerplate generation, but review and adapt all generated code manually.

---

### Requirements

Your implementation must:

* use header guards
* define methods outside the class if they are longer than a few lines
* use `const` where appropriate
* avoid raw owning pointers
* compile with `-std=c++20 -Wall -Wextra -pedantic`
* keep the design simple

Example command:

```bash
g++ -std=c++20 -Wall -Wextra -pedantic sensor.cpp temperature_sensor.cpp main.cpp -o sensor_demo
./sensor_demo
```

---

### Required Result

Submit all generated and reviewed source files plus a file:

```text
section_7_boilerplate.md
```

Answer:

```text
1. Which parts were generated by Copilot?
2. Which parts did you write or modify manually?
3. Did Copilot create unnecessary complexity?
4. Was the generated boilerplate consistent with good C++ style?
5. What would be dangerous about accepting generated boilerplate without review?
```
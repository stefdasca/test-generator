# Competitive Programming Test Case Generator using GPT (recommended to use GPT o4-mini-high)

We have attached as an example one of the problems generated using our method:

You must compile the generator and the model code as follows:

Generator: g++ -std=gnu++17 -O2 -o generator.exe generator.cpp
Source code: g++ solution.cpp -o solution.exe

In the helpers you have the batch scripts we used during our work.

For a given problem, after you generate the output using our prompt and compile the generator and the model code, you must use the batch scripts from the helpers.zip file to generate the test cases and to run the model code on them.

In short, the workflow goes like this:

1. You use the prompt to generate a generator and some parameters for the test cases.
2. You use script.bat to generate the tests themselves
3. You use the tests generated and a correct solution (yours or someone else's) and run run_all.bat.

Sometimes the output might hallucinate so it's best to make it stick to these models. In practice, it is quite adaptive and I welcome any potential improvements.

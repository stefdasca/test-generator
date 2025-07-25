# Competitive Programming Test Case Generator using GPT (recommended to use GPT o4-mini-high)

We have attached as an example one of the problems generated using our method:

You must compile the generator and the model code as follows:

Generator: g++ -std=gnu++17 -O2 -o generator.exe generator.cpp
Source code: g++ solution.cpp -o solution.exe

In the helpers you have the batch scripts we used during our work.

For a given problem, after you generate the output using our prompt and compile the generator and the model code, you must use the batch scripts from the helpers.zip file to generate the test cases and to run the model code on them.
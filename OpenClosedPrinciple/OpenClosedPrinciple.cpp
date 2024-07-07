//Open-Closed Principle

#include <iostream>
#include <vector>
#include <string>

class Question {
public:
	Question() = default;
	Question(std::string _question) :
		question(_question)
	{
	}
	Question(std::string _question,
		std::vector<std::string> _answers,
		std::vector<bool> _correctAnswers) :
		question(_question),
		answers(_answers),
		correctAnswers(_correctAnswers)
	{
	}
	std::string question{ "" };
	std::vector<std::string> answers{};
	std::vector<bool> correctAnswers{};
	virtual void showQuestion(int id) {
		std::cout << "[Question " + std::to_string(id) + "] " << question << std::endl;
	}
	virtual void showAnswers() {}
	virtual void checkCorrectAnswers() {}
};

struct Boolean : public  Question
{
	Boolean(std::string _question,
		std::vector<std::string> _answers,
		std::vector<bool> _correctAnswers
	) :Question(_question, _answers, _correctAnswers)
	{

	}
	virtual void showAnswers() override {
		std::cout << "Chose the correct: "
			<< answers.at(0) << "/"
			<< answers.at(1)
			<< std::endl;
	}
	virtual void checkCorrectAnswers() override {
		std::string input{ "" };
		std::cin >> input;
		int answerIndex = -1;
		if (input == "Yes") {
			answerIndex = 0;
		}
		else if (input == "No") {
			answerIndex = 1;
		}
		else {
			//throw std::runtime_error("Boolean case failed!");
			std::cout << "Not answered!\n";
			return;
		}

		if (correctAnswers.at(answerIndex))
		{
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Wrong!\n";
		}

	}
};
struct SingleChoice : public  Question
{
	SingleChoice(std::string _question,
		std::vector<std::string> _answers,
		std::vector<bool> _correctAnswers
	) :Question(_question, _answers, _correctAnswers)
	{

	}
	virtual void showAnswers() override
	{
		for (size_t j = 0; j < answers.size(); j++)
		{
			std::cout << answers.at(j) << std::endl;
		}
	}
	virtual void checkCorrectAnswers() override
	{
		std::string input{ "" };
		std::cin >> input;
		bool flag = false;
		for (size_t i = 0; i < answers.size(); i++) {
			if (input == answers.at(i)) {
				if (correctAnswers.at(i)) {
					flag = true;
				}
			}
		}
		if (flag) {
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Wrong!\n";
		}
	}
};
struct MultipleChoice : public  Question
{
	MultipleChoice(std::string _question,
		std::vector<std::string> _answers,
		std::vector<bool> _correctAnswers
	) :Question(_question, _answers, _correctAnswers)
	{

	}
	inline void ltrim(std::string& s) {
		s.erase(
			s.begin(), std::find_if(
				s.begin(), s.end(), [](unsigned char ch) {
					return !std::isspace(ch);
				}));
	}
	inline void rtrim(std::string& s) {
		s.erase(
			std::find_if(
				s.rbegin(), s.rend(), [](unsigned char ch) {
					return !std::isspace(ch);
				}).base(), s.end()
					);
	}
	inline void trim(std::string& s) {
		rtrim(s);
		ltrim(s);
	}
	std::vector<std::string> split(std::string s, std::string delimiter) {
		size_t pos_start = 0, pos_end, delim_len = delimiter.length();
		std::string token;
		std::vector<std::string> res;

		while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
			token = s.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			res.push_back(token);
		}

		res.push_back(s.substr(pos_start));
		return res;
	}
	virtual void showAnswers() override
	{
		for (size_t j = 0; j < answers.size(); j++)
		{
			std::cout << "[" + std::to_string(j + 1) + "] " + answers.at(j) << std::endl;
		}
	}
	virtual void checkCorrectAnswers() override
	{
		std::string input{ "" };
		std::cin >> input;
		std::vector<bool> flags;
		std::vector<int> givenAnswers;
		try {
			std::vector<std::string> list = split(input, ",");
			for (size_t i = 0; i < list.size(); i++)
			{
				givenAnswers.push_back(std::stoi(list.at(i)) - 1);
			}
		}
		catch (std::exception& e) {
			return;
		}

		flags.resize(correctAnswers.size());

		for (size_t j = 0; j < givenAnswers.size(); j++)
		{
			for (size_t i = 0; i < correctAnswers.size(); i++) {
				if (givenAnswers.at(j) == correctAnswers.at(i)) {
					if (correctAnswers.at(i)) {
						flags.at(i) = true;
					}
				}
			}
		}
		bool isCorrect{ true };
		for (size_t i = 0; i < flags.size(); i++)
		{
			if (flags.at(i) != correctAnswers.at(i)) {
				isCorrect = false;
			}
		}
		if (isCorrect) {
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Wrong!\n";
		}
	}
};

struct Text : public Question
{
	Text(std::string _question,
		std::vector<std::string> _answers,
		std::vector<bool> _correctAnswers
	) :Question(_question, _answers, _correctAnswers)
	{

	}
	virtual void checkCorrectAnswers() override
	{
		std::string input{ "" };
		std::cin >> input;
		if (input == answers.front()) {
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Wrong!\n";
		}
	}
};

class Quiz {

	std::vector<Question> m_questions;
public:
	Quiz() {
		m_questions.emplace_back(
			Boolean("Is 1MB == 1MiB?", { "Yes","No" }, { false,true }));
		m_questions.emplace_back(
			SingleChoice(
				"What is the ascii code of character 'A'?",
				{ "45","68","97","65" },
				{ 0,0,0,1 })
		);
		m_questions.emplace_back(
			MultipleChoice(
				"Which of the following are correct?",
				{ "Type 'int' is always 32 bits.",
				"OCP is one of the SOLID principles.",
				"Singleton is one of the SOLID principles.",
				"Assembly is programing language." },
				{ 0,1,0,1 })
		);
		m_questions.emplace_back(
			Text(
				"How many bits are there in Question struct?",
				{ "1024" },
				{ 1 })
		);
	}

	void start() {
		for (size_t i = 0; i < m_questions.size(); i++)
		{
			int a = 5;
			m_questions.at(i).showQuestion(i + 1);
			m_questions.at(i).showAnswers();
			m_questions.at(i).checkCorrectAnswers();
		}
	}
};
int main() {
	Quiz quiz;
	quiz.start();
	return EXIT_SUCCESS;
}


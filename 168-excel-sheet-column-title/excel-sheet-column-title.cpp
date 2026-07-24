class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;

		while ( columnNumber > 0)
		{
			columnNumber--;

			char letter = columnNumber % 26 + 'A';

			title += letter;
			columnNumber /= 26;
		}

		reverse(title.begin(), title.end());

		return title;
    }
};
#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <cassert>

class FileManager
{
public:
	FileManager(const std::wstring& filename)
		:
		filename(filename)
	{}

	std::vector<std::wstring> GetLineVector() const
	{
		std::vector<std::wstring> list;
		std::wifstream input( filename );
		
		assert( !input.fail() );

		for (std::wstring str; std::getline( input, str );)
		{
			if (str.empty())
			{
				continue;
			}
			list.push_back( str );
		}
		input.close();
		return list;
	}
	void SaveToFile( const std::vector<std::wstring>& data )
	{
		std::wofstream output( filename );

		for (const auto& str : data)
		{
			output << str;
		}
		output.close();
	}

private:
	std::wstring filename;
};
#include "file.h"

namespace SpriterEngine
{

	File::File(std::string initialFilePath) :
		filePath(initialFilePath)
	{

	}

	ImageFile *File::imageFile()
	{
		return 0;
	}

	SoundFile *File::soundFile()
	{
		return 0;
	}

	AtlasFile *File::atlasFile()
	{
		return 0;
	}

	void File::setPath(std::string newPath)
	{
		this->filePath = newPath;
	}

	std::string File::path()
	{
		return filePath;
	}

}

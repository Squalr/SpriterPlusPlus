#ifndef FILE_H
#define FILE_H

#include <string>

namespace SpriterEngine
{

	class ImageFile;
	class SoundFile;
	class AtlasFile;

	class File
	{
	public:
		File(std::string initialFilePath);
		virtual ~File() {}

		virtual ImageFile *imageFile();
		virtual SoundFile *soundFile();
		virtual AtlasFile *atlasFile();

		void setPath(std::string newPath);
		std::string path();

	protected:
		std::string filePath;
	};

}

#endif // FILE_H

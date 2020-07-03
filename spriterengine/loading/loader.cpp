#include "loader.h"

#include "../global/settings.h"

#include "../override/spriterfiledocumentwrapper.h"
#include "../override/filefactory.h"

namespace SpriterEngine
{
	Loader::Loader(FileFactory * newFileFactory) :
		fileFactory(newFileFactory)
	{
	}

	Loader::~Loader()
	{
	}

	void Loader::loadFile(SpriterModel * model, const std::string &fileName)
	{
		static std::map<std::string, SpriterFileDocumentWrapper*> WrapperMap = std::map<std::string, SpriterFileDocumentWrapper*>();
		SpriterDocumentLoader spriterDocumentLoader;
		SpriterFileDocumentWrapper* wrapper = nullptr;
		SpriterFileType fileType = extractFileTypeFromFileName(fileName);

		if (WrapperMap.find(fileName) != WrapperMap.end())
		{
			wrapper = WrapperMap[fileName];
		}
		
		switch (fileType)
		{
			case SPRITERFILETYPE_SCML:
			{
				if (wrapper == nullptr)
				{
					wrapper = fileFactory->newScmlDocumentWrapper();
					wrapper->loadFile(fileName);
				}

				if (wrapper)
				{

					spriterDocumentLoader.loadFile(model, wrapper, fileName);
				}
				else
				{
					Settings::error("Loader::loadFile - attempting to load scml file \"" + fileName + "\" : no scml document wrapper found");
				}
				break;
			}
			case SPRITERFILETYPE_SCON:
			{
				if (wrapper == nullptr)
				{
					wrapper = fileFactory->newSconDocumentWrapper();
				}
				
				if (wrapper)
				{
					spriterDocumentLoader.loadFile(model, wrapper, fileName);
				}
				else
				{
					Settings::error("Loader::loadFile - attempting to load scon file \"" + fileName + "\" : no scon document wrapper found");
				}
				break;
			}
			default:
			{
				Settings::error("Loader::loadFile - attempting to load file \"" + fileName + "\" : unrecognized file type");
				break;
			}
		}

		WrapperMap[fileName] = wrapper;
	}

	Loader::SpriterFileType Loader::extractFileTypeFromFileName(const std::string &fileName)
	{
		size_t lastDot = fileName.find_last_of(".");
		if (lastDot != std::string::npos)
		{
			std::string extension = fileName.substr(lastDot + 1, std::string::npos);

			if (extension == "scml")
			{
				return SPRITERFILETYPE_SCML;
			}
			else if (extension == "scon")
			{
				return SPRITERFILETYPE_SCON;
			}
			else
			{
				Settings::error("Loader::extractFileTypeFromFileName - file \"" + fileName + "\" : unrecognized file type");
			}
		}
		else
		{
			Settings::error("Loader::extractFileTypeFromFileName - file \"" + fileName + "\" : unable to extract extension from file name");
		}
		return SPRITERFILETYPE_NONE;
	}
}



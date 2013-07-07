
#ifndef SAMPLE_PLUGIN_HPP
#define SAMPLE_PLUGIN_HPP

#include <iostream>
#include "plumage/plugin_interface.hpp"

class SamplePluginDeleter : public plumage::PluginDeleter {
public:
    virtual void operator()(plumage::PluginInterface* p) const {
        delete p;
    }
};

class SamplePlugin : public plumage::PluginInterface {
public:
    SamplePlugin(std::string name) : plumage::PluginInterface(name, new SamplePluginDeleter())
    {}

    virtual ~SamplePlugin() {
        std::cout << "SamplePlugin destruct." << std::endl;
    }

    virtual int getInterfaceVersion() const {
        return 1;
    }
    virtual int getPluginVersion() const {
        return 1;
    }
    virtual bool isDebug() const {
        return true;
    }

    virtual bool isCompatible(int interfaceVersion) const {
        return true;
    }

    virtual bool isCallable(const std::string& methodName) const {
        return true;
    }

protected:
    virtual bool doStart() {
        std::cout << "SamplePlugin start" << std::endl;
        return true;
    }
    virtual bool doStop() {
        std::cout << "SamplePlugin stop" << std::endl;
        return true;
    }

    virtual void* doCall(std::string methodName, void* paramter) {
        std::cout << methodName << " called." << std::endl;
        return nullptr;
    }
};

#endif

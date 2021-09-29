namespace lone {
    namespace renderer {
        class Window {
        private:
            int width, height;
            const char *name;
        public:
            Window(int width, int height, const char *name);
            void Init() const;
        };
    }
}


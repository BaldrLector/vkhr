#ifndef VKHR_HAIR_STYLE_HH
#define VKHR_HAIR_STYLE_HH

#include <glm/glm.hpp>

#include <string>
#include <iostream>
#include <vector>

namespace vkhr {
    class HairStyle {
    public:
        HairStyle() = default;
        HairStyle(const std::string& file_path);

        enum class Error {
            None,

            OpeningFile,
            ReadingFileHeader,
            WritingFileHeader,

            InvalidSignature,

            ReadingSegments,
            ReadingVertices,
            ReadingThickness,
            ReadingTransparency,
            ReadingColor,

            WritingSegments,
            WritingVertices,
            WritingThickness,
            WritingTransparency,
            WritingColor,

            InvalidFormat
        };

        operator bool() const;
        Error get_previous_failure_code() const;

        bool load(const std::string& file_path);
        bool save(const std::string& file_path) const;

        std::size_t get_strand_count() const;
        std::size_t get_vertex_count() const;

        bool has_segments() const;
        bool has_vertices() const;
        bool has_thickness() const;
        bool has_transparency() const;
        bool has_color() const;

        unsigned get_default_segment_count() const;
        void set_default_segment_count(unsigned default_segment_count);
        void set_default_thickness(float default_thickness);
        float get_default_thickness() const;
        float get_default_transparency() const;
        void set_default_transparency(float default_transparency);
        void set_default_color(const glm::vec3& default_color);
        glm::vec3 get_default_color() const;

        std::string get_information() const;
        void set_information(const std::string& information);

        // Let the user do what he pleases with the hair data.
        // Consistency with arrays is checked upon file write.

        std::vector<unsigned short> segments;
        std::vector<glm::vec3> vertices;
        std::vector<float> thickness;
        std::vector<float> transparency;
        std::vector<glm::vec3> color;

    private:
        struct FileHeader {
            char signature[4]; // H, A, I, R.
            unsigned strand_count,
                     vertex_count;

            struct {
                // FIXME: make more portable?!
                unsigned has_segments     : 1,
                         has_vertices     : 1,
                         has_thickness    : 1,
                         has_transparency : 1,
                         has_color        : 1,
                         future_extension : 27;

            } field;

            unsigned default_segment_count;
            float    default_thickness,
                     default_transparency;
            float    default_color[3];

            char information[88];
        };

        bool valid_signature() const;
        bool format_is_valid() const;

        void complete_header() const;
        void update_bitfield() const;

        bool read_segments(std::ifstream& file);
        bool read_vertices(std::ifstream& file);
        bool read_thickness(std::ifstream& file);
        bool read_transparancy(std::ifstream& file);
        bool read_color(std::ifstream& file);

        bool write_segments(std::ofstream& file) const;
        bool write_vertices(std::ofstream& file) const;
        bool write_thickness(std::ofstream& file) const;
        bool write_transparancy(std::ofstream& file) const;
        bool write_color(std::ofstream& file) const;

        mutable Error fail_bit { Error::None };
        mutable FileHeader file_header;
    };
}

#endif
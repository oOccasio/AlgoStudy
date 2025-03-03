package chuchu.miniproject.domain;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@Entity
@NoArgsConstructor
public class Team {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false, length = 25)
    private String name;

    @Column(length = 25)
    private String manager;

    @Column
    private Integer memberCount;

    public Team(String name, String manager, Integer memberCount) {
        if(name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException(String.format("유효하지 않은 이름입니다: %s", name));
        }
        if(name.length() > 25) {
            throw new IllegalArgumentException("팀 이름은 25자를 초과할 수 없습니다.");
        }
        if(manager.length() > 25) {
            throw new IllegalArgumentException("매너지 이름은 25자를 초과할 수 없습니다.");
        }

        this.name = name;
        this.manager = manager;
        this.memberCount = (memberCount == null) ? 0 : memberCount;
    }



}
